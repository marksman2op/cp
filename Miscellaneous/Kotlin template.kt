//IDE: https://www.jdoodle.com/compile-kotlin-online/
import java.io.PrintWriter
import java.util.*
import java.util.Scanner
import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }
// println(OUTPUT_LINES.joinToString("\n"))
        
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
@JvmField val _reader = System.`in`.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
 
@JvmField val _writer = PrintWriter(System.out, false)
inline fun output(block: PrintWriter.()->Unit) { _writer.apply(block).flush() }
fun iprintln(o: Any?) { println(o) } // immediate println for interactive, bypasses output{} blocks
*/

/*
https://kotlinlang.org/docs/tutorials/kotlin-for-py/introduction.html
https://kotlinlang.org/docs/tutorials/competitive-programming.html
https://www.tutorialspoint.com/kotlin/index.htm
https://www.javatpoint.com/kotlin-tutorial
https://www.programiz.com/kotlin-programming
*/
