#include "MiscAlgorithm.h"
#include "ExecuteInterface.h"


class AlgorithmExecutor : public IExecuteInterface
{
public:
	// 디폴트 생성자는 실행할 알고리즘에 대해 null로 초기화합니다.
	AlgorithmExecutor() = default;

	// 주어진 인터페이스로 알고리즘을 생성하는 생성자입니다.
	AlgorithmExecutor(IExecuteInterface* InExecute)
	{
		RegisterAlgorithm(InExecute);
	}



public:
	void RegisterAlgorithm(IExecuteInterface* InExecute)
	{
		if (InExecute == nullptr)
		{
			ALG_LOG("IExecuteInterface가 유효하지 않습니다");
			return;
		}

		AlgorithmToExecute = InExecute;
	}

	// 알고리즘 유효성을 체크하고 실행합니다.
	virtual void Execute() override
	{
		if (AlgorithmToExecute == nullptr)
		{
			ALG_LOG("해당 알고리즘이 유효하지 않습니다");
			return;
		}

		AlgorithmToExecute->Execute();
	}

private:
	IExecuteInterface * AlgorithmToExecute;
};





#include "Public\MazeRecursive.h"
#include "CountingCellsInBlob.h"
#include "NQueens.h"

static AlgorithmExecutor GAlgorithmExecutor;

int main()
{
	GAlgorithmExecutor.RegisterAlgorithm(new NQueens());
	GAlgorithmExecutor.Execute();
	return 0;
}

// 문제는 해당 알고리즘의 클래스 헤더 파일에서 정의합니다.
