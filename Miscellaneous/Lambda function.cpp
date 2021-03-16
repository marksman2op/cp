// Lambda function
// https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
// [capture list](parameters) -> return value { body }
auto p = [&](int x) { // auto = function<return_type(parameter_dataypes_seprated_by_comma)>
	// Do work
    // Will show error if you try to return 2 different types
};

auto choose = [&](int n) -> int {  // explicitly specify the return type
    if (n <= 1) {
        return 0LL;
    } else {
        return n * (n - 1) / 2;
    }
};

// Lambda function in comparator
sort(v.begin(), v.end(), [](const pair<int, int> x, const pair<int, int> y) {
    if (x.first != y.first) {
        return x.first < y.first;
    }
    return x.second > y.second;
});

// Lambda function in recursive functions
const std::function<int(int)> factorial = [&factorial](int n) {
        return n > 1 ? n * factorial(n - 1) : 1;
};

// Passing by reference
int x;
vector<int> a;

auto lambda = [x, &a](...) {
    ...
};