import 'styled-components'
import theme from './theme'

export type Theme = typeof theme

declare module 'styled-components' {
    export interface DefaultTheme extends Theme {
        colors: {
            white: string
            black: string
            primary: string
            primaryLight: string
            primaryDark: string
            greyLight1: string
            greyLight2: string
            greyLight3: string
            greyLight4: string
            greyDark1: string
            greyDark2: string
            greyDark3: string

            background: string
            backgroundLight: string
            backgroundDark: string
        }
        sizes: {
            borderRadius: string
        }
    }
}
