#include "Serializer.hpp"
#include <cassert>

int main(void)
{
	Data *data = new Data();
	data->iso = 200;
	data->brand = "Kodak";
	data->name = "Gold";
	data->bw = false;

	auto ser_res = Serializer::serialize(data);
	auto deser_res = Serializer::deserialize(ser_res);
	assert(data == deser_res);

	std::cout << "\nJust checking if deserialized pointer can be used to access data:\n";
	std::cout << deser_res->brand << std::endl;
	delete data;
	return 0;
}
