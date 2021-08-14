//Exponential recursion is a recursion that we may not know how much times the function calls back it.

//it can be used to arrange an array

//obviously need an array
//second is the length of array
//because I want for loop starts from the begin of the array so let i = 0.
void Permuations(int arr[], int n, int i = 0;)
{
	int j, swap;
	for(j = i+1; j < n; j++)
	{
		if(arr[i] > arr[j])
		{
			swap = arr[j];
			arr[j] = arr[i];
			arr[i] = swap;
		}
		//if arr[i] < arr[j] nothing will happen
		//jump with i++
		Permuations(arr, n, i+1);
	}
}
