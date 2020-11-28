#include"ANIMALS.h"
#include"Repository.h"

class AnimalsRepo : Repository {
public:
	AnimalsRepo(bool sync = false);
	~AnimalsRepo();

	animals* Get(int ind) { return (animals*)data[ind]; };
	void Show();

};