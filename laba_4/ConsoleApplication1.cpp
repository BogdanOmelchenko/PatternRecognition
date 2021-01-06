// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//





#include <iostream>
using namespace std;

void postroenie(int A[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (A[i][j] == 0)
			{
				cout << A[i][j] << " ";
			}
			else if ((j + 1) % 3 == 0 && j < 7)
			{
				cout << A[i][j] << "|";
			}
			else
			{
				cout << A[i][j] << " ";
			}
		}
		if ((i + 1) % 3 == 0 && i < 7)
		{
			cout << endl;
			cout << "- - - - - - - - -";
			cout << endl;
		}
		else
		{
			cout << endl;
		}
	}
}
int sosedi(int i, int j, int K[9][9])
{

	for (int k = 0; k < 9; k++)
	{
		for (int l = 0; l < 9; l++)
		{
			K[k][l] = 0;
		}
	}
	for (int k = 0; k < 9; k++)
	{
		for (int l = 0; l < 9; l++)
		{
			if (k == i || l == j)
			{
				K[k][l] = 1;
			}
		}
	}
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 3; l++)
		{
			if (i % 3 == k && j % 3 == l)
			{
				for (int z = 0; z < 3; z++)
				{
					for (int x = 0; x < 3; x++)
					{
						K[i - k + z][j - l + x] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			return K[i][j];
		}

	}
}
int startovie_znachenya(int S[9][9], int q[9][9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				q[i][j][k] = 1;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (S[i][j] != 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (S[i][j] - 1 != k)
					{
						q[i][j][k] = 0;
					}
					else if (S[i][j] - 1 == k)
					{
						q[i][j][k] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			for (int k = 0; k < 9; k++)
			{
				return  q[i][j][k];
			}

		}
	}
}
int perehod_k_chislam(int q[9][9][9], int B[9][9])
{

	int l, m;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			B[i][j] = 0;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			l = 0;
			m = 0;
			for (int k = 0; k < 9; k++)
			{
				l = l + q[i][j][k];
				if (q[i][j][k] == 1)
				{
					m = k + 1;
				}
			}
			if (l == 1)
			{
				B[i][j] = m;
			}
			else
			{
				B[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			return B[i][j];
		}
	}
}
int proverka(int q[9][9][9])
{
	int l, m = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			l = 0;

			for (int k = 0; k < 9; k++)
			{
				l = l + q[i][j][k];
			}
			if (l == 0)
			{
				m = 1;
			}
		}
	}
	return m;
}
int algoritm_vicherkivaniya(int h[9][9][9])
{
	int l, A[9][9], C[9][9], B[9][9], m, x, w = 0;
	int V[9][9][9];
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			B[i][j] = 0;
		}
	}*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				V[i][j][k] = h[i][j][k];
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			l = 0;
			m = 0;
			for (int k = 0; k < 9; k++)
			{
				l = l + h[i][j][k];
				if (h[i][j][k] == 1)
				{
					m = k;
				}
			}
			if (l == 1)
			{
				sosedi(i, j, B);
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (B[i][j] == 1)
						{
							h[i][j][m] = 0;
						}
					}
				}
				h[i][j][m] = 1;
			}
		}
	}
	x = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				x = x + h[i][j][k];
			}
		}
	}
	if (proverka(h) == 1)
	{
		cout << "ne vyidet" << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					return h[i][j][k];
				}
			}
		}
	}
	else if (proverka(h) == 0 && x == 81)
	{
		cout << "konets" << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					return h[i][j][k];
				}
			}
		}
	}
	else if (proverka(h) == 0 && x > 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					if (V[i][j][k] == h[i][j][k])
					{
						w = w + 1;
						
					}
					
				}
			}
		}
		if (w == 729)
		{
			cout << "nado rasmetki algoritm" << endl;
			perehod_k_chislam(h, C);
			postroenie(C);
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					for (int k = 0; k < 9; k++)
					{
						return h[i][j][k];

					}
				}
			}
		}
		cout << "nado prodolzhat" << endl;
		algoritm_vicherkivaniya(h);

	}
	
}
int poisk_rasmetki(int m[9][9][9])
{
	int g[9][9][9], a[9][9][9], b[9][9][9], c[9][9][9], u, q = 0, x = 0, y = 0, z = 0, o = 0, l, d = 0, E[9], W[9], r;

	algoritm_vicherkivaniya(m);
	algoritm_vicherkivaniya(g);
	algoritm_vicherkivaniya(a);
	algoritm_vicherkivaniya(b);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				g[i][j][k] = m[i][j][k];
				a[i][j][k] = m[i][j][k];
				b[i][j][k] = m[i][j][k];
				c[i][j][k] = m[i][j][k];
				x = x + g[i][j][k];
				y = y + a[i][j][k];
				z = z + b[i][j][k];
				o = o + c[i][j][k];
			}
		}
	}
	if (proverka(g) == 1 && x == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					return g[i][j][k];
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				u = 0;
				r = 0;
				l = 0;
				int e = 0;
				for (int k = 0; k < 9; k++)
				{
					l = l + a[i][j][k];
					e = e + a[i][j][k];
					E[k] = a[i][j][k];
					W[k] = a[i][j][k];


				}
				if (l > 1)
				{
					
					for (int w = 0; w < 9; w++)
					{
						if (e > 1 && a[i][j][w] == 1)
						{
							a[i][j][w] = 0;
							e--;
						}
						if (e == 1 && a[i][j][w] == 1)
						{
							r = w;
						}
						
					}

					if (proverka(a) == 0)
					{
						algoritm_vicherkivaniya(a);
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								for (int k = 0; k < 9; k++)
								{
									if (m[i][j][k] == a[i][j][k])
										u = u + 1;
								}
							}
						}
						if (u == 729)
						{
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									for (int k = 0; k < 9; k++)
									{
										return m[i][j][k];
									}
								}
							}

						}
						else if (proverka(a) == 1)
						{
							b[i][j][r] = 0;
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									for (int k = 0; k < 9; k++)
									{
										a[i][j][k] = b[i][j][k];
									}
								}
							}


						}
						else
						{
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									for (int k = 0; k < 9; k++)
									{
										m[i][j][k] = a[i][j][k];
									}
								}
							}

							break;

						}
					}
					else
					{
						b[i][j][r] = 0;
						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								for (int k = 0; k < 9; k++)
								{
									a[i][j][k] = b[i][j][k];
								}
							}
						}
					}
					

				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					return m[i][j][k];
				}
			}
		}
	}
}

int main()
{
	int Q[9][9][9];
	int A[9][9], B[9][9] = {
		{8, 1, 0, 0, 3, 0, 0, 2, 7},
		{0, 6, 2, 0, 0, 0, 0, 9, 0},
		{0, 7, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 6, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 4},
		{0, 0, 8, 0, 0, 5, 0, 7, 0},
		{0, 0, 0, 0, 0, 0, 0, 8, 0},
		{0, 0, 0, 0, 1, 0, 7, 5, 0},
		{0, 0, 0, 0, 7, 0, 0, 4, 2}
	};

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				Q[i][j][k] = 1;
			}
		}
	}
	startovie_znachenya(B, Q);
	poisk_rasmetki(Q);
	cout << endl << endl;
	perehod_k_chislam(Q, A);
	cout << endl;
	postroenie(A);
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}*/
	system("pause");
	return 0;
}

