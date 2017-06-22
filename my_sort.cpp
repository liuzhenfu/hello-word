//快速快速快排
// 该方法的基本思想是：
//1．先从数列中取出一个数作为基准数。
//2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
//3．再对左右区间重复第二步，直到各区间只有一个数。
//对挖坑填数进行总结
//1．i =L; j = R; 将基准数挖出形成第一个坑a[i]。
//2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。
//3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。
//4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。

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
// 合并有序数组
void mergeArray(int a[],int first, int mid, int last, int tmp[])
{
	int i,j,k;
	i = first; j = mid+1; k = 0;
	while(i <= mid && j <= last)
	{
		if(a[i] > a[j])
		{
			tmp[k++] = a[j++];
		}
		else 
		{
			tmp[k++] = a[i++];
		}
	}
	while(i <= mid)
	{
		tmp[k++] = a[i++];
	}
	while(j <= last)
	{
		tmp[k++] = a[j++];
	}
	for(i = 0;i < k;++i)
	{
		a[first+i] = tmp[i];
	}
	for(int i=0;i<=9;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void merge_sort(int a[], int first, int last, int tmp[])
{
	if(first < last)
	{
		merge_sort(a,first,(first+last)/2,tmp);
		merge_sort(a,(first+last)/2+1,last,tmp);
		mergeArray(a,first,(first+last)/2,r,tmp);
	}
}
