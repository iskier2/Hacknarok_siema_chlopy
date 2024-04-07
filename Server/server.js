const http = require('http');
const fs = require('fs');
const path = require('path');


const sqlite3 = require('sqlite3').verbose();

// Connect to the SQLite database
const db = new sqlite3.Database('cmake-build-debug/SKW.db');
// Create a table

const server = http.createServer((req, res) => {
    // Handle requests to the root path
    if (req.url === '/') {
        // Read the index.html file
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
    }
    // Handle GET request to /data
    else if (req.url === '/data' && req.method === 'GET') {
        // Send some sample data as JSON
        res.writeHead(200, {'Content-Type': 'application/json'});
        db.serialize(() => {

            // Query the data
            db.each("SELECT * FROM main", (err, row) => {
                if (err) {
                    console.error(err.message);
                }
                res.end(JSON.stringify(row));
            });
        });



    }
    // Handle other paths
    else {
        res.writeHead(404);
        res.end('Error: Endpoint not found');
    }
});

// Start the server on port 3000
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});