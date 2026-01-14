WITH st AS (
    SELECT 
        student_id,
        subject
    FROM Scores
    GROUP BY student_id, subject
    HAVING COUNT(*) >= 2
),
temp AS (
    SELECT 
        student_id,
        subject,
        exam_date,
        FIRST_VALUE(score) OVER (
            PARTITION BY student_id, subject 
            ORDER BY exam_date
        ) AS first_score,
        FIRST_VALUE(score) OVER (
            PARTITION BY student_id, subject 
            ORDER BY exam_date DESC
        ) AS latest_score
    FROM Scores
)

SELECT DISTINCT
    t.student_id,
    t.subject,
    t.first_score,
    t.latest_score
FROM st s
JOIN temp t
    ON s.student_id = t.student_id
   AND s.subject = t.subject
where t.first_score < t.latest_score;
