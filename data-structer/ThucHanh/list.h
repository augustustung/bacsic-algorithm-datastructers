#ifndef list_h
#define list_h

#include <iostream>
using namespace std;

template <class T>

class List 
{
private:
	T ds[5000];
	int N;
public:
	List() { N = 0; };

	void Add(T v) 
	{
		ds[N++] = v;
	};

	void Update(int pos, T v) 
	{
		ds[pos - 1] = v;
	};

	void Delete(int pos)
	{
		bool find = false;
		for(int i = pos - 1; i < N; i++) 
		{
			ds[i] = ds[i+1];
			find = true;
		}
		if (!find) {
			cout << "Khong tim thay\t" << pos << endl;
		} else {
			N--;
			cout << "Xoa thanh cong"<< endl;
		}
	};

	void Delete(int start, int end)
	{
		int index = start;
		for(int i = end; i < N; i++) {
			ds[index] = ds[i];
			index++;
		}
		N-=(end - start);
	};


	T Get(int pos) const 
	{
		return ds[pos-1];
	};

	int Count() const
	{
		return N;
	};

	int Count(T val) const
	{
		int counter = 0;
		for(int i = 0; i < N; i++) {
			if (ds[i] == val) {
				counter++;
			}
		}

		return counter;
	};

	void Insert(int pos, T v)
	{
		for (int i = N; i >= pos; i--)
		{
			ds[i] = ds[i-1];
		}
		ds[pos - 1] = v;
		N++;
	}

	void Swap(int pos1, int pos2) {
		T t = ds[pos1-1];
		ds[pos1-1] = ds[pos2-1];
		ds[pos2-1] = t;
	};

	int findFirstIndex(T val) {
		for(int i = 0; i < N; i++) {
			if (ds[i] == val) {
				return i + 1;
			}
		}
		return -1;
	};

	int findLastIndex(T val) {
		int index = -1;
		for(int i = 0; i < N; i++) {
			if (ds[i] == val) {
				index = i + 1;
			}
		}

		return index;
	};

	void Replace(int pos, T val) {
		ds[pos-1] = val;
	};

	void Replace(int start, int end, T val) {
		for (int i = start - 1; i < end - 1; i++) {
			ds[i] = val;
		}
	};


	bool Some(int val) {
		bool isExisting = false;
		for(int i = 0; i < N; i++) {
			if (ds[i] == val) {
				isExisting = true;
				break;
			}
		}

		return isExisting;
	};

	T *Find(T minimum, T maximum) {
   	static T result[5000];
	  for (int i = 0; i < N; i++) {
	  	if (ds[i] <= maximum && ds[i] >= minimum) {
	  		result[i] = ds[i];
	  	} else {
	  		result[i] = 0;
	  	}
	  }
   
   	return result;
	};

	T *FindExec(int start, int end) {
   	static T result[5000];
   	int index = 0;
	  for (int i = start - 1; i < end - 1; i++) {
	  	result[index] = ds[i];
	  	index++;
	  }
   
   	return result;
	};

	T *Slice(int startPos, int endPos) {
		static T result[5000]; 
		int index = 0;
		for (int i = startPos; i < endPos; i++) {
			result[index] = ds[i];
			index++;
		}
		return result;
	};

	void Print() {
		for (int i = 0; i < N; i++) {
			cout << this->Get(i+1) << "\t";
		}
		cout << endl;
	};

	void Print(int start, int end) {
		for (int i = start; i < end; i++) {
			cout << this->Get(i) << "\t";
		}
		cout << endl;
	};

	T *Revert() {
		static T result[5000]; 
		int index = 0;
		for (int i = N-1; i > N/2; i--) {
			result[index] = ds[i];
			index++;
		}

		for (int i = N/2; i >= 0; i--) {
			result[index] = ds[i];
			index++;
		}
		return result;
	};


	void DeleteByVal(T val) {
		int i = this->Count();
		while (i >= 1) {
			if (this->Get(i) == val) {
				this->Delete(i);
			}
			i--;
		};
	}
};

#endif