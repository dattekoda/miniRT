# Error Message
## validate arguments
- no file name  
	"miniRT: set .rt file as an argument"
- dot file  
	miniRT: file name starting with '.' is not supported.
- file extention  
	miniRT: File extension needs to be '.rt'."

## validate line list
- no ambient  
	miniRT: set only one Ambient
- no camera  
	miniRT: set only one Camera

# validate ambient
- no space  
	miniRT: need space  
	A 0.5 X 1.0, ...  
	^
- lighting ratio is out of range  
	miniRT: ambient lighting ratio out of the range [0.0,1.0]
- 