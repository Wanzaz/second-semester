/* Put your data in here and query it! */

/* Source: http://www.boxofficemojo.com/alltime/world/ */
CREATE TABLE topmovies(
   Rank        INTEGER,
   Title       TEXT,
   Studio      TEXT,
   Worldwide   REAL,
   Domestic    REAL,
   DomesticPct REAL,
   Overseas    REAL,
   OverseasPct REAL,
   Year        INTEGER
);

INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (1,'Avatar','Fox',2788.00,760.50,0.27,2027.50,0.73,2009);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (2,'Titanic','Par.',2186.80,658.70,0.30,1528.10,0.70,1997);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (3,'Marvel''s The Avengers','BV',1518.60,623.40,0.41,895.20,0.59,2012);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (4,'Harry Potter and the Deathly Hallows Part 2','WB',1341.50,381.00,0.28,960.50,0.72,2011);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (5,'Furious 7','Uni.',1322.20,321.20,0.24,1001.00,0.76,2015);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (6,'Frozen','BV',1274.20,400.70,0.31,873.50,0.69,2013);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (7,'Iron Man 3','BV',1215.40,409.00,0.34,806.40,0.66,2013);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (8,'Transformers: Dark of the Moon','P/DW',1123.80,352.40,0.31,771.40,0.69,2011);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (9,'The Lord of the Rings: The Return of the King','NL',1119.90,377.80,0.34,742.10,0.66,2003);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (10,'Skyfall','Sony',1108.60,304.40,0.28,804.20,0.73,2012);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (11,'Transformers: Age of Extinction','Par.',1091.40,245.40,0.23,846.00,0.78,2014);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (12,'The Dark Knight Rises','WB',1084.40,448.10,0.41,636.30,0.59,2012);
INSERT INTO topmovies(Rank,Title,Studio,Worldwide,Domestic,DomesticPct,Overseas,OverseasPct,Year) VALUES (13,'Pirates of the Caribbean: Dead Man''s Chest','BV',1066.20,423.30,0.40,642.90,0.60,2006);


SELECT * FROM topmovies;

/*
What are average, max, and min values in the data?
*/
SELECT ROUND(AVG(Worldwide)) AS average_worldwide_views FROM topmovies;
SELECT ROUND(SUM(Worldwide)) AS whole_worldwide_views FROM topmovies;
SELECT ROUND(MIN(Worldwide)) AS mininal_worldwide_views FROM topmovies;
SELECT ROUND(MAX(Worldwide)) AS maximal_worldwide_views FROM topmovies;


/*
What about those numbers per category in the data (using HAVING)?
*/
/* Select movies which have over 1200 average views and after that are group by Rank */
SELECT Title, AVG(Worldwide) AS avg_worldwide_views FROM topmovies
    GROUP BY Rank
    HAVING avg_worldwide_views > 1200
    ;

/* Select studio which has more then 3 movies in this list*/
SELECT Studio COUNT FROM topmovies
    GROUP BY Studio
    HAVING COUNT(*) >= 3
    ;

/*Assign to every studio the number of the movies that the studio have in this db*/
SELECT Studio, COUNT(*) COUNT FROM topmovies
    GROUP BY Studio
    ;

/*
What ways are there to group the data values that don’t exist yet (using CASE)?
*/
SELECT COUNT(), 
    CASE
        WHEN Worldwide > 1500 THEN "Masterpiece"
        WHEN Worldwide > 1200 THEN "Good one"
        WHEN Worldwide > 900 THEN "Little bit worse"
        ELSE "Don't even watch it"
    END AS "movie_recommendation"
FROM topmovies
GROUP BY movie_recommendation;

/*
What interesting ways are there to filter the data (using AND/OR)?
*/
SELECT Title FROM topmovies WHERE 1500 < Worldwide AND Year > 2010;
