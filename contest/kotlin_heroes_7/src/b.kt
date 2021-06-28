fun go2() {
    val ay = readLine()!!.split(" ").map { it.toLong() }
    val a : Long = ay[0]
    val b : Long = ay[1]
    val x : Long = ay[2]
    var ans : Long = 0
    ans += a*((x+1)/2)
//    print(ans.toString() + " ")
    ans -= b * (x/2)
    println(ans)
}
fun main() {
    var t = readLine()!!.toInt()
    while(--t >= 0) {
        go2()
    }
}