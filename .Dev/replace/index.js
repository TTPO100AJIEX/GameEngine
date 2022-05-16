const fs = require('fs');

var patterns = fs.readFileSync(`${__dirname}/patterns.cpp`, "utf-8");
var from = fs.readFileSync(`${__dirname}/from.cpp`, "utf-8");

patterns = patterns.split('\r\n')
                .map(el => ({"from": el.substring(0, el.indexOf("=") - 1), "to": el.substring(el.indexOf("=") + 2)}))
                .sort((a, b) => a.from.length > b.from.length ? -1 : a.from.length == b.from.length ? 0 : 1);
patterns.forEach(pattern =>
{
    from = from.replaceAll(pattern.from, pattern.to);
});

fs.writeFileSync(`${__dirname}/result.cpp`, from, "utf-8");