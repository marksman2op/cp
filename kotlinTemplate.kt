//IDE: https://www.jdoodle.com/compile-kotlin-online/
import java.io.PrintWriter
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }
        
fun main(args: Array<String>) {
    
    var t = readInt()
    for(tc in 0..(t - 1)) {
        var (n, k) = readInts()
        var ac = readInts()
        var a = Array(n) {0}
        for(i in 0..(n - 1))
            a[i] = ac[i] 
 
        var b = Array(n) {it}
        b.sortBy{-a[it]}
        
        var ans = Array(n) {0}
        for(i in 0..(n - 2)) {
            var x = b[i]
            var y = b[i + 1]
            var diff = a[x] - a[y] - 1
            if(diff >= k) {
                diff = k
                k = 0
            }
            else 
                k -= diff
                
            ans[y] += diff
            a[y] += diff
        }
        
        for(i in 0..(n - 1)) {
            var x = b[i]
            ans[x] += k / n + (if (k % n > i) 1 else 0)
        }
        
        for(i in 0..(n - 1)) {
            print("${ans[i]} ")
        }
        println()
 
    }
    
}

/*
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
*/

/*
https://kotlinlang.org/docs/tutorials/kotlin-for-py/introduction.html
https://kotlinlang.org/docs/tutorials/competitive-programming.html
https://www.tutorialspoint.com/kotlin/index.htm
https://www.javatpoint.com/kotlin-tutorial
https://www.programiz.com/kotlin-programming
*/
