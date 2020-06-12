SELECT movies.title, ratings.rating FROM movies 
JOIN ratings on ratings.movie_id = movies.id WHERE year = 2010 ORDER BY rating DESC, title ASC;
