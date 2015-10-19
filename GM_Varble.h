//ŠÖ”ŠÇ——p
#define MAX_ADD 99
struct _varbles
{
	int name;
	int body;
};
class CVarble
{
private:
	_varbles varbles[MAX_ADD];
	int Max;
public:
	void Add_varbles(int num,int name);
	void Delete_varbles(int name);
	void Move_varbles(int num,int name);
	int Return_varbles(int name);
	void Alldelete_varbles(void);
	void Reset_varbles(void);
};
extern CVarble varble_body;