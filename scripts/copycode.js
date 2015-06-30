var fs = require('fs'),
    dirs = fs.readdirSync('./'),
    path = require('path'),
    notFound = [],
    x;

if (process.argv.indexOf('--dive')) {
  x = [];
  dirs.forEach(function(d) {
    var ds = fs.readdirSync(d).map(function(i) {
      return path.join(d, i);
    });
    x.push.apply(x, ds);
  });
  dirs = x;
}

dirs.forEach(function(d) {
  try {
    var t = fs.readFileSync(path.join(d, '.git/config'), 'utf8');

    console.log('mkdir %s; cd %s', d, d);
    console.log('git init');
    console.log('printf "%s" > .git/config',
                t.replace(/\n/g, '\\n').replace(/\t/g, '\\t')
                 .replace(/"/g, '\\"'));
    console.log('git pull');
    console.log('cd ..');

  } catch(e) {
    if (d[0] != '.') notFound.push(d);
  }
});


console.log('\n\n\n\n\n');
console.log('Not working:', notFound.join('\n'));
