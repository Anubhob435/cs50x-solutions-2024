-- 11.sql
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman')) ORDER BY (SELECT MAX(rating) FROM ratings WHERE movie_id = movies.id) DESC LIMIT 5;
