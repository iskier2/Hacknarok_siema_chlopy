const http = require('http');
const fs = require('fs');
const path = require('path');


const sqlite3 = require('sqlite3').verbose();

// Connect to the SQLite database
const db = new sqlite3.Database('cmake-build-debug/SKW.db');
// Create a table
db.serialize(() => {

    // Query the data
    db.each("SELECT * FROM main", (err, row) => {
        if (err) {
            console.error(err.message);
        }
        console.log(row);
    });
});

const server = http.createServer((req, res) => {
    // Set content type to HTML
    res.writeHead(200, {'Content-Type': 'text/html'});

    // Read the HTML file
    fs.readFile(path.join(__dirname, 'index.html'), (err, data) => {
        if (err) {
            res.writeHead(404);
            res.write('File not found!');
        } else {
            // Send the HTML content to the client
            res.write(data);
        }
        res.end();
    });
});

const PORT = process.env.PORT || 3000;

server.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
