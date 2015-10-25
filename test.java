static int x = 10;

...

static Foobar y;

class Foobar

{

public:

Foobar() { assert(x == 10); } // Constructor

};
