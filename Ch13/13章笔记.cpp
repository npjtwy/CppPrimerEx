/*
	使用 =default
		通过将拷贝控制成员（拷贝构造， 赋值运算符，析构函数）定义为 =default 来显式地要求编译器生成合成的版本
*/
class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(const Sales_data&) = default;
	~Sales_data() = default;
	Sales_data& operator=(const Sales_data&);
};
Sales_data& Sales_data::operator=(const Sales_data&) = default;

/*
	阻止拷贝
		通过定义为删除的函数来阻止类的拷贝
	析构函数不能是删除的函数
*/
struct NpCopy
{
	NpCopy() = delete;
	NpCopy(const NpCopy&) = delete;
	~NpCopy() = default;
	NpCopy& operator=(const NpCopy) = delete;
};
