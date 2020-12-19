fun main() {
    var (a, b) = readLine()!!.split(' ').map { it.toInt() }
    println(a - b + 1);
}