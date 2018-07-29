
#define maxint 100
struct stacki {
  int stk[maxint];
  int top;
}nest;
void ipush( struct stacki *x,int a)
{
	if(x->top == maxint -1)
		return;
	else
	{
		x->top+= 1;
		x->stk[x->top]= a;
	} // else
} // push

int  ipop(struct stacki * x)
{
	if(x->top == -1)
		return -1;
	else
	{
    x->top -= 1;
		return x->stk[x->top+1];
	} // else
} // pop
