#include <iostream>

// Роберт получил в наследство робота-дровосека, который умеет выполнять две
// операции: +3 и *4. Выполняя первую команду робот колет +3 полена дров,
// выполняя втоорую, увеличивает общеее количество дров в 4 раза. Роберт хочет
// понять за какое минимальное количество операций робот может получить Y дров,
// если изначальное число дров X.
//
// Пример:
// in: 10 19
// out: 3
//
//

#define ERROR_CODE_OPERATION_CNT   (-1)

typedef int FirewoodCnt;
typedef int OpCnt;

// -----------------------------------------------------------------------------
static void RobotTryAddFirewood(FirewoodCnt* cur_firewood) {
  *cur_firewood += 3;
}

// -----------------------------------------------------------------------------
static void RobotTryMultiplicationFirewood(FirewoodCnt* cur_firewood) {
  *cur_firewood *= 4;
}

// -----------------------------------------------------------------------------
static void IncreaseOpCnt(OpCnt* cur_op_cnt) {
  *cur_op_cnt += 1;
}

// -----------------------------------------------------------------------------
static OpCnt TryToMakeDesiredFirewood(FirewoodCnt cur,
                                      FirewoodCnt desired) {
  FirewoodCnt temp_firewood = cur;
  OpCnt op_cnt = 0;

  while (cur < desired) {
    RobotTryMultiplicationFirewood(&cur);
    if (cur > desired) {
      cur = temp_firewood;
      while (cur < desired) {
        RobotTryAddFirewood(&cur);

        if (cur > desired) {
          return ERROR_CODE_OPERATION_CNT;
        } else {
          IncreaseOpCnt(&op_cnt);
        }
      }
    } else {
      temp_firewood = cur;
      IncreaseOpCnt(&op_cnt);
    }
  }

  if (cur > desired) {
    return ERROR_CODE_OPERATION_CNT;
  }
  return op_cnt;
}

// -----------------------------------------------------------------------------
int main(int argc, char const* argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);

  FirewoodCnt cur_firewood;
  FirewoodCnt desired_firewood;
  OpCnt operation_cnt;

  std::cin >> cur_firewood;
  std::cin >> desired_firewood;

  if (cur_firewood == desired_firewood) {
    std::cout << 0;
  } else if (cur_firewood > desired_firewood) {
    std::cout << ERROR_CODE_OPERATION_CNT;
  } else {
    operation_cnt = TryToMakeDesiredFirewood(cur_firewood, desired_firewood);
    std::cout << static_cast<int>(operation_cnt);
  }
  return EXIT_SUCCESS;
}
