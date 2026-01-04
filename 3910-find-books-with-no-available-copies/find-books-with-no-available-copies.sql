
select 
    l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    COUNT(b.book_id) AS current_borrowers
    
from library_books l
join borrowing_records b
on l.book_id = b.book_id
where b.return_date is null 
group by l.book_id,l.total_copies
HAVING COUNT(b.book_id) = l.total_copies
ORDER BY current_borrowers DESC, title ASC;