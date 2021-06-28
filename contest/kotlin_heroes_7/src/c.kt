fun go3() {
    val ay = readLine()!!.split(" ").map { it.toInt() }
    val n : Int = ay[0]
    val k : Int = ay[1]
    for (i in 0..n-1) {
        print('a'+i.rem(k))
    }
    println("")

}

fun main() {
    var t = readLine()!!.toInt()
    while(--t >= 0) {
        go3()
    }
}