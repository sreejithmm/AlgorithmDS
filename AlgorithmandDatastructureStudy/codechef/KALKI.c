//http://www.codechef.com/problems/KALKI

typedef unsigned long long ULL;
typedef long long LL;


mytree* makeNode(LL x, LL y)
{
	mytree* node = (mytree*)malloc(sizeof(mytree));

	node->xcord = x;
	node->ycord = y;
	node->right = NULL;
	node->left = NULL;

	/*TODO*/
	
	return node;
}

int main()
{

	ULL nT;
	ULL n;
	LL x,y;
	mytree * node;

	scanf("%d",&nT);
	while(nT)
	{
		scanf("%d",&n);
		while(n)
		{
			scanf("%d %d",&x,&y);
			node = makeNode();

		}
		
	}
}