#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> sorted;
int N;

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */
void Merge(vector<int>& v, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;
	//���� ���ĵ� ����Ʈ �պ�
	while (i <= mid && j <= end)
	{
		if (v[i] <= v[j])
		{
			sorted[k] = v[i];
			i++;
		}
		else
		{
			sorted[k] = v[j];
			j++;

		}
		k++;
	}

	int entry = (i > mid) ? j : i;
	int target = (i > mid) ? end : mid;
	//���� �ִ� ���� ���� 
	for (int t = entry; t <= target; ++t)
	{
		sorted[k] = v[t];
		k++;
	}
	//���ĵ� �ӽ� ����Ʈ��  ���� ����Ʈ�� ���� 
	for (int t = start; t <= end; ++t)
	{
		v[t] = sorted[t];
	}



}

void MergeSort(vector<int>& v, int start, int end)
{
	if (sorted.size() == 0)
	{
		sorted = vector<int>(v.size());
	}
	if (start < end)
	{
		int mid = (start + end) / 2;  // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		MergeSort(v, start, mid);  // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		MergeSort(v, mid + 1, end); // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		Merge(v, start, mid, end); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)


	}
}


int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	MergeSort(v, 0, v.size() - 1);
	for (auto& e : v)
	{
		cout << e << "\n";

	}


	return 0;
}