project(Riskdice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(Riskdice
   Dice.cpp
   RiskDice.cpp
)
 
