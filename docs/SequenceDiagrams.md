## next to do
- put pixels on window
- calucurate phong color
- calucurate ray color
- set_objects

```mermaid
flowchart

subgraph mini_rt
		direction TB
	start([start])-->|CLI arguments|m1[[init world]]
	m1-->|world|m2[[render world]]
	m2-->|pixels color data|m3[[put pixels on window]]
	m3-->|EXIT_SUCCESS|r([return])
end

```
```mermaid
flowchart
	subgraph	init_world
		direction TB
		input[/CLI arguments/]-->|argv1|sw1
		sw1[[validate arguments]]-->|valid file path|sw2
		sw2[read .rt file]-->|line list|if1{validate line list}
		if1-->|invalid|e([exit])
		if1-->|valid line list|sw4[[create world]]
		sw4-->|world|output[\world\]
		input-->|argv2|sw5[set option]
		sw5-->|option flag|output
	end
```
```mermaid
flowchart
	subgraph validate_arguments
		direction TB
		input[/argv1/]-->|argv1|if1{validate file name}
		if1-->|invalid|exit([exit])
		if1-->|valid|output[\valid file path\]
	end
```

```mermaid
flowchart
%% 	subgraph validate_line_list [validate line list]
%% 		direction TB
%% 		input[/line list/]-->|each line|validate_line
%% 		subgraph validate_line
%% 			direction TB
%% 			vlin[/line/]-->|head of line|if1{find
%% 			match identifer}
%% 			if1-->|no match|error
%% 			if1-->|match: A, C, L, sp, pl, cy...|if2{validate
%% 			with the identifier}
%% 			if2-->|valid|vlout[\valid line\]
%% 			if2-->|invalid|error
%%% 		error([error])
%% 		end
%% 		validate_line-->|each line|output[\valid line list\]
%% 	end
```

```mermaid
flowchart
	subgraph validate_line_list [validate line list]
		direction TB
		input[/line list/]-->for
		for----->|false|output[\valid line list\]
		for{more line?}-->|true|vlin
		vlin[/line/]-->|head of line|if1{find
			match identifer}
		if1-->|no match|error
		if1-->|match: A, C, L, sp, pl, cy...|if2{validate
			with the identifier}
		if2-->|valid|for
		if2-->|invalid|error
		error([error])
	end
```

```mermaid
sequenceDiagram
autonumber
    Actor ユーザー
    participant 画面 as フロントエンド
    participant サーバー as 認証サーバー
    participant DB as データベース

    ユーザー->>+画面: ログインボタン押下
    画面->>+サーバー: ID/PW送信
    サーバー->>+DB: ユーザー照会
    DB-->>-サーバー: ユーザーデータ
    サーバー-->>-画面: 認証成功レスポンス
    画面-->>-ユーザー: トップ画面表示
```
```mermaid
stateDiagram-v2

```

```mermaid
flowchart
	subgraph create_world [create world]
		direction TB
		input[/valid line list/]
		cw1[set background]
		cw2[set camera]
		cw3[set light]
		cw4[[set objects]]
		input-->|line list|cw1 & cw2 & cw3 & cw4
		cw1-->|background|output
		cw2-->|camera|output
		cw3-->|light list|output
		cw4-->|bvh|output[\world\]
	end
```

```mermaid
flowchart
	subgraph set_objects [set objects]
		direction TB
	input[/line list/]-->|L, ph, pl, cy...|if1{L included?}
	if1-->|path tracing: Yes|so1[create objects list]
	if1-->|phong: No|so1
	so1-->|objects having aabb:
	ph, cy, tr...|so2[create bvh]
	so1-->|objects having no aabb:
	pl, co...|so3[create objects list]
	so2-->|bvh -> left arm|output[\root of bvh\]
	so3-->|object list -> right arm|output[\root of bvh\]
	end
```
```mermaid
flowchart
	subgraph render_world [render world]
		direction TB
		for--->|false|output[\pixcels color data\]
		for{next pixel?}-->|true|input
		input[/world/]-->rw1
		rw1[[get pixel color]]-->for
	end
```
```mermaid
flowchart
	subgraph get_pixel [get pixel color]
		direction TB
		for----->|false|fp0[avarage of samples]
		fp0-->output[\pixel color\]
		for{next sample?}-->|true|input
		input[/world/]-->gp1[get ray from camera to pixel]
		gp1-->|ray|if1{mode is}
		if1-->|Phong|gp2[[calucurate 
		phong color]]
		if1-->|path tracing|gp3[[calucurate 
		ray color]]
		gp2 & gp3-->|color|color[acumulate samples]
		color-->for
		
	end
```

```mermaid
flowchart
	subgraph cal_phong_color [calucurate phong color]
		direction TB
		input[/ray/]
		output[/color/]
	end
```

































```mermaid
flowchart	
```