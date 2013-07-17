// ���͵Ķ�̬�滮,�õݹ��µļ��仯������ʵ��
// ״̬ת�Ʒ��� �Ϸ��������:DP(i,j) = max( DP(i,j-1), DP(i,j+1), DP(i-1,j), DP(i+1,j) ) + 1;
#include <iostream>
using namespace std;

int matrix[100][100];// ����ԭʼ����
int cnt[100][100]; // ��¼ÿһ��������ѩ����
int row ,col;

int DP(int i, int j)
{
	int max = 0;

	// ����Ѿ������,ֱ�ӷ���(���仯����Ч��֮���Ըߵ�ԭ��:���ظ�����)
	if (cnt[i][j] > 0) 
	{
		return cnt[i][j];
	}

	// �����Ŀ����,ֻ�ԺϷ���i��j,���еݹ�(�ݹ���ص����:��ȥ���в��Ϸ���,ֻ�������кϷ���!!!)
	if (j-1 >= 0)
	{
		if (matrix[i][j] > matrix[i][j-1])
		{
			if (max < DP(i, j-1))
			{
				max = DP(i, j-1);
			}
		}
	}

	if (j+1 <= col-1)
	{
		if (matrix[i][j] > matrix[i][j+1])
		{
			if (max < DP(i, j+1))
			{
				max = DP(i, j+1);
			}
		}
	}

	if (i-1 >= 0)
	{
		if (matrix[i][j] > matrix[i-1][j])
		{
			if (max < DP(i-1, j))
			{
				max = DP(i-1, j);
			}
		}
	}

	
    // ��������������SB�ؽ�row��д��col,�������е������������������ݶ�û������,����һ�ύ��Wa
	// ע��,�������ܲ���������!!!!
	if (i+1 <= row-1)
	{
		if (matrix[i][j] > matrix[i+1][j])
		{
			if (max < DP(i+1, j))
			{
				max = DP(i+1, j);
			}
		}
	}

	// �������¼��cnt������(���仯�������ص�)

	// ����������¶�û��һ�����ֵ��������ֵ��,��cnt[i][j] = max+1 = 1
	// �����������¸������ѩ���ȼ�¼��max��, ��cnt[i][j] = max+1 
	// �����maxΪʲôҪ��ʼ��Ϊ0��ԭ��.
	return cnt[i][j] = max + 1;
}


int main()
{
   
	int i, j; 
	cin>>row>>col;

	// ��ʼ������
	for (i=0; i<=row-1; i++)
	{
		for (j=0; j<=col-1; j++)
		{
			cin>>matrix[i][j];
			cnt[i][j] == 0;
		}
	}

	// ����ÿһ����,�������ѩ���ȱ�����cnt��������
	for (i=0; i<=row-1; i++)
	{
		for (j=0; j<=col-1; j++)
		{
			DP(i, j);
		}
	}


	// ��������,�����ֵ,��������Ϊ��cnt��д��matrix��wa��һ��,�治Ӧ��!!!
	for (i=0; i<=row-1; i++)
	{
		for (j=0; j<=col-1; j++)
		{
			if (cnt[0][0] < cnt[i][j])
			{
				cnt[0][0] = cnt[i][j];
			}
		}
	}
	
	cout<<cnt[0][0]<<endl;

    return 0;
}