// Lambda function
// https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
auto p = [&](int x) { // auto = function<return_type>
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