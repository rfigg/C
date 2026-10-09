/* Define macro swap(t,x,y) that interchanges two arguments of type t */

#define swap(t,x,y) { t _c;   \
                      _c = x; \
                      x = y;  \
                      y = _c; }
/* Could that work? */
/* Mine would not have worked. The block structure in their answer contains
their local variable, and they use an underscore variable, assuming that 
underscore variable will not be used as one of the parameters.
However the idea and format is there. The block structure avoids creating a new
variable after the macro. The underscore local variable makes conflict with
parameter less likely. Slash at end of line makes it format better. */
