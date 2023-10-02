/* when you use 'static' when assigning a variable,
it does not destroy the output when made a local varialble.
*/

int increment()
{
    static int count;
    count = count + 1;
    return count;
}
