# Write your MySQL query statement below
select 
    book_id,
    title,
    author,
    genre,
    publication_year,
    current_borrowers
from (
    select 
        l.book_id,
        l.title,
        l.author,
        l.genre,
        l.publication_year,
        sum(coalesce(return_date,1)) as current_borrowers,
        l.total_copies
    from library_books l
    join borrowing_records b
    on l.book_id = b.book_id
    where b.return_date is null 
    group by book_id
    having sum(coalesce(return_date,1)) = l.total_copies
)as t
ORDER BY current_borrowers DESC, title ASC;