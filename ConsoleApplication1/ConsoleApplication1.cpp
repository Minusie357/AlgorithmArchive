/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <time.h>
#pragma warning(disable : 4996)

using namespace std;

int Answer;
clock_t start, end;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/


	freopen("sample_input.txt", "r", stdin);
	int jmp[320000];
	jmp[0] = 0;

	for (int i = 1; i < 320000; ++i)
	{
		jmp[i] = jmp[i-1] + i;
	}

	scanf("%d",&T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int x = 0, y = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		///////////////////////
	
		int maxcount = 0;

		for (int i = x; i <= y; ++i)
		{
			int loccount = 0;
			int mod = i;
			for (int j = 150; j > 0; --j)
			{
				if (mod >= jmp[j])
				{
					loccount += j;
					mod -= jmp[j];
				}

				if (jmp[j] == 1 && mod == 1)
				{
					loccount+= 1;
					mod -= 1;
				}
			}	

			if (maxcount < loccount)
				maxcount = loccount;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		Answer = maxcount;
		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}