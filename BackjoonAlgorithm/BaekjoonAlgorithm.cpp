#include <iostream>


char check_board[50][50];

int min_fix_count = 50 * 50;
int min_r_offset = -1;
int min_c_offset = -1;

void count_need_fix_color(int r_start, int c_start, char origin_color)
{
	// 8x8 체스판을 검사하기 위한 좌상단 색을 메인색으로 한다.
	char main_color = origin_color;
	// 메인색이 아닌 색을 반대색이라고 한다.
	char count_color;
	// 메인색을 체크해야 하는지, 반대색을 체크해야하는 지 플래그 
	bool main_flag = true;

	// 반대색을 설정하기 위한 분기문
	if (origin_color == 'W')
	{
		count_color = 'B';
	}
	else
	{
		count_color = 'W';
	}

	int main_color_fix_count = 0;
	int count_color_fix_count = 0;
	int local_min_fix_count = 2500;

	// 체크 시작
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (main_flag)
			{
				if (main_color != check_board[r_start + i][c_start + j])
				{
					main_color_fix_count++;
				}
			}
			else
			{
				if (count_color != check_board[r_start + i][c_start + j])
				{
					main_color_fix_count++;
				}
			}

			main_flag = !main_flag;
		}

		main_flag = !main_flag;
	}



	main_flag = true;

	char temp_color = main_color;
	main_color = count_color;
	count_color = temp_color;



	// 체크 시작
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (main_flag)
			{
				if (main_color != check_board[r_start + i][c_start + j])
				{
					count_color_fix_count++;
				}
			}
			else
			{
				if (count_color != check_board[r_start + i][c_start + j])
				{
					count_color_fix_count++;
				}
			}

			main_flag = !main_flag;
		}

		main_flag = !main_flag;
	}





//	std::cout << r_start << "," << c_start << " :: " << main_color_fix_count << " vs " << count_color_fix_count << std::endl;
	main_color_fix_count > count_color_fix_count ?
		local_min_fix_count = count_color_fix_count :
		local_min_fix_count = main_color_fix_count;

	if (local_min_fix_count < min_fix_count)
	{
		min_fix_count = local_min_fix_count;
		min_r_offset = r_start;
		min_c_offset = c_start;
	}

}

int main()
{
	FILE* input;
//	freopen_s(&input, "sample.txt", "r", stdin);

	int N, M;
	std::cin >> N;
	std::cin >> M;

	char* Mbuffer = new char[M+1];

	for (int i = 0; i < N; ++i)
	{
		std::cin >> Mbuffer;
		for (int j = 0; j < M; ++j)
		{
			check_board[i][j] = Mbuffer[j];
		}
	}

	for (int i = 0; i < N - 7; ++i)
	{
		for (int j = 0; j < M - 7; ++j)
		{
			count_need_fix_color(i, j, check_board[i][j]);
		}
	}

	std::cout << min_fix_count;
}
