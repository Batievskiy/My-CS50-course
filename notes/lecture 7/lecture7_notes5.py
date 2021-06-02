import csv

from cs50 import SQL

# this is a pythonic way of creating an empty file
open("shows.db", "w").close()

# opening an empty yet file as SQL databade
db = SQL("sqlite:///shows.db")

# let's create a table of shows
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")

# and create a table of genres
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()

        # and let's insert all of the shows into db database
        id = db.execute("INSERT INTO shows (title) VALUES(?)", title)  # ? - placeholder
        # and insert all of the genras
        for genre in row["genres"].split(", "):  # .split(", ") - takes all comas and split genres
            db.execute("INSERT INTO genres (show_id, genre) VALUES(?, ?)", id, genre)

