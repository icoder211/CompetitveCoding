    priority_queue<pair<int, int>> q; // -dis, node
	q.push(mp(0, a));
	dis[a] = 0;
	while(!q.empty()) {
		auto u = q.top();q.pop();
		if(vis[u.second]) continue;
		// cout << u.second << ln;
		int y = u.second;
		vis[y] = 1;
		for(auto p: ad[y]) {
			// cout << p << ln;
			if(vis[p]) continue;
			if(dis[p] > dis[y] + 1) {
				dis[p] = dis[y] + 1;
				q.push(mp(-dis[p], p));
			}
		}
	}
	
	if(dis[b] >= 1e9)cout << "IMPOSSIBLE\n";
	else cout<<dis[b] << ln;