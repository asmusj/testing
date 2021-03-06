#ifndef DRAMAOBJ_H
#define DRAMAOBJ_H
#include "movieobject.h"


class DramaObj : public MovieObject {
	friend ostream& operator<<(ostream& output, const DramaObj& toWrite);
public:
	DramaObj();
	DramaObj(string, string);
	virtual ~DramaObj();
	virtual Object* create() const;
	virtual void setData(ifstream&);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;

protected:

};

#endif