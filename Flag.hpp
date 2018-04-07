#pragma once

class Flag {
public:
	Flag()
		: req(nullptr), val(true) {}
	Flag(Flag* req)
		: req(req) {}

	bool isComplete() { return val; }
	void complete();

private:
	bool val;
	Flag* req;
};
