/*
	ʹ�� =default
		ͨ�����������Ƴ�Ա���������죬 ��ֵ���������������������Ϊ =default ����ʽ��Ҫ����������ɺϳɵİ汾
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
	��ֹ����
		ͨ������Ϊɾ���ĺ�������ֹ��Ŀ���
	��������������ɾ���ĺ���
*/
struct NpCopy
{
	NpCopy() = delete;
	NpCopy(const NpCopy&) = delete;
	~NpCopy() = default;
	NpCopy& operator=(const NpCopy) = delete;
};
