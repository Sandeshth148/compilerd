#define max 100
struct stack {
  char stk[max][80];
  int top;
}tokens;
void push( struct stack *x,char a[80])
{
	if(x->top == max -1)
		return;
	else
	{
		x->top+= 1;
		strcpy(x->stk[x->top], a);
	} // else
} // push

char * pop(struct stack * x)
{
	if(x->top == -1)
		return "\0";
	else
	{
    x->top -= 1;
		return x->stk[x->top+1];
	} // else
} // pop
