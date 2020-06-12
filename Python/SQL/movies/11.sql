SELECT title FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE id in 
(SELECT movie_id FROM stars WHERE person_id = 
( SELECT id FROM people WHERE name = "Chadwick Boseman")) order by rating DESC LIMIT 5;
