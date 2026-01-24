```mermaid
flowchart
	subgraph init world
	direction TB
	input1[/*world, argc, argv/]
	input1-->func1
	func1[validate arguments]
	func1-->func2
	func2[set option]
	end
```