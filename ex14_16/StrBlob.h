#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
	using size_type = std::vector<std::string>::size_type;

public:
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}

	StrBlob(const StrBlob &sb) :data(make_shared<vector<string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob&);

	StrBlob(StrBlob &&rhs) noexcept : data(std::move(rhs.data)) {}
	StrBlob& operator=(StrBlob &&) noexcept;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	size_type size()const {
		data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(const string &t) {
		data->push_back(t);
	}
	void push_back(string &&s) {
		data->push_back(std::move(s));
	}

	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
private:
	void check(size_type, const std::string&) const;
	std::shared_ptr<std::vector<std::string>> data;
};

