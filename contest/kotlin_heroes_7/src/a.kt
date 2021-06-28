fun go1() {
    val ay = readLine()!!.split(" ").map { it.toInt() }
    val a = ay[0]
    val b = ay[1]
    val c = a + b
    println(c)
}

fun main() {
    var t = readLine()!!.toInt()
    while(--t >= 0) {
        go1()
    }
}