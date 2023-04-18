CREATE TABLE celebs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    email TEXT,
    single BOOL
);

INSERT INTO celebs (name, email, single) VALUES 
    ("Harvey Specter", "harvey.specter@gmail.com", TRUE);
INSERT INTO celebs (name, email, single) VALUES 
    ("Donna Paulsen", "donna.paulsen@gmail.com", TRUE);
INSERT INTO celebs (name, email, single) VALUES 
    ("Justin Bieber", "justin@gmail.com", FALSE);

CREATE TABLE movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    celebrity_id INTEGER,
    title TEXT,
    release_year INTEGER
);

INSERT INTO movies (celebrity_id, title, release_year) VALUES 
    (2, "Interstellar", 2009);
INSERT INTO movies (celebrity_id, title, release_year) VALUES 
    (1, "Suits", 2011);
INSERT INTO movies (celebrity_id, title, release_year) VALUES 
    (3, "Concert", 2012);

SELECT * FROM movies;
SELECT * FROM celebs;

SELECT celebs.name, movies.title, movies.release_year 
    FROM celebs
    JOIN movies
    ON celebs.id = celebrity_id;
