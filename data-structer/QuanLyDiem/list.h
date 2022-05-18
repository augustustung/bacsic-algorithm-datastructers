#ifndef list_h
#define list_h

template <class T>

class List 
{
private:
	T ds[150];
	int N;
public:
	List() { N = 0; }
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
			N--;
		}
		if (!find) {
			cout << "Khong tim thay\t" << pos << endl;
		} else {
			cout << "Xoa thanh cong\t" << pos << endl;
		}
	}

	T Get(int pos) const 
	{
		return ds[pos-1];
	}

	void Insert(int pos, T v)
	{
		for (int i = N; i >= pos; i--)
		{
			ds[i] = ds[i-1];
		}
		ds[pos - 1] = v;
		N++;
	}

	int Count() const
	{
		return N;
	}
 
};

#endif