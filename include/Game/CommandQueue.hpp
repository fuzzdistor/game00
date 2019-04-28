//CommandQueue.hpp
#ifndef COMMANDQUEUE_HPP
#define COMMANDQUEUE_HPP

#include <Game/Command.hpp>

#include <queue>

class CommandQueue
{
public:
	void 		push(const Command& command);
	Command 	pop();
	bool		isEmpty() const;

private:
	std::queue<Command>		mQueue;
}


#endif //CommandQueue.hpp