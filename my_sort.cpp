//快速快速快排
void quick_sort(int a[],int l,int r)
{
	if(l < r)
	{
		int i = l,j = r, p = a[l];
		while (i < j)
		{
			while(j > i && a[j] > p)
			{
				--j;
			}
			if(j > i)
			{
				a[i++] = a[j];
			}
			while(i < j && a[i] < p)
			{
				++i;
			}
			if(i < j)
			{
				a[j++] = a[i];
			}
		}
		a[i] = p;
		quick_sort(a,l,i-1);
		quick_sort(a,i+1,r);
	}
	
}