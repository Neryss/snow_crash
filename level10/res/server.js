const	express = require('express')
const	app = express();

app.get('/', (req, res) => {
	res.send("yo");
})

app.listen(6969, () => {
	console.log("listening on 6969");
})