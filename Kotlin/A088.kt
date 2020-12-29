import java.io.PrintWriter
import java.util.Arrays;
import java.util.Collections;
val pw = PrintWriter(System.out)

fun get() = readLine()!!
fun getint() = get().toInt()
fun getlong() = get().toLong()
fun getdouble() = get().toDouble()
fun vs() = get().split(" ")
fun vi() = get().split(" ").map(String::toInt).toTypedArray()
fun vll() = get().split(" ").map(String::toLong).toTypedArray()
fun vllSort() = get().split(" ").map(String::toLong).toTypedArray().sortedArray()
fun vllrSort() = get().split(" ").map(String::toLong).toTypedArray().sortedArrayDescending()
fun vd() = get().split(" ").map(String::toDouble).toTypedArray()
fun vdSort() = get().split(" ").map(String::toDouble).toTypedArray().sortedArray()
fun vdrSort() = get().split(" ").map(String::toDouble).toTypedArray().sortedArrayDescending()

fun divisor(value : Long) : List<Long> {
    val max = Math.sqrt(value.toDouble()).toLong()
    return (1..max)
        .filter { value % it == 0L }
        .map { listOf(it, value / it) }
        .flatten()
        .sorted()
}

fun prime(from : Long, to : Long = from) : List<Long> {
    return (from..to).filter { i ->
        val max = Math.sqrt(i.toDouble()).toLong()
        (2..max).all { j ->  i % j != 0L }
    }
}

fun decom(value : Long) : List<Long>{
    if (value == 1L) return listOf(1)
    val max = Math.sqrt(value.toDouble()).toLong()
    return prime(2, max).filter { value % it == 0L }
}

fun gcd(a : Long, b : Long) : Long {
    return if (a % b == 0L) b else gcd(b, a % b)
}

fun swap(base : String, a : String, b : String) : String {
    return base.map {
        when (it) {
            a.toCharArray()[0] -> b
            b.toCharArray()[0] -> a
            else -> it.toString()
        }
    }.joinToString()
}

fun println(value : Any) {
    pw.println(value)
}

fun main(args : Array<String>) {
    solve()
    pw.flush()
}

fun solve() {
    val n = getint()
    val a = getint()
    val r = if (a >= n%500) "Yes" else "No"
    println(r)
}