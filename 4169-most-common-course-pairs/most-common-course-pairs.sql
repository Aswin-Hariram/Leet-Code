WITH top_students AS (
    SELECT user_id
    FROM course_completions
    GROUP BY user_id
    HAVING COUNT(*) >= 5
       AND AVG(course_rating) >= 4
),
ordered AS (
    SELECT
        c.user_id,
        c.course_name,
        c.completion_date,
        ROW_NUMBER() OVER (
            PARTITION BY c.user_id
            ORDER BY c.completion_date
        ) AS rn
    FROM course_completions c
    INNER JOIN top_students ts
        ON ts.user_id = c.user_id
),
pairs AS (
    SELECT
        o1.user_id,
        o1.course_name AS course_A,
        o2.course_name AS course_B
    FROM ordered o1
    INNER JOIN ordered o2
        ON o1.user_id = o2.user_id
       AND o2.rn = o1.rn + 1
)
SELECT
    course_A AS first_course,
    course_B AS second_course,
    COUNT(*) AS transition_count
FROM pairs
GROUP BY
    course_A,
    course_B
ORDER BY
    transition_count DESC,
    course_A ASC,
    course_B ASC;
