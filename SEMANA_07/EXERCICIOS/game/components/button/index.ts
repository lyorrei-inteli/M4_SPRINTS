import styled from 'styled-components'

export const Button = styled.button`
    outline: none;
    border: none;
    border: 1px solid ${(props) => props.theme.colors.white};
    padding: 1rem 2rem;
    border-radius: ${(props) => props.theme.sizes.borderRadius};
    font-size: 3rem;
    background: none;
    color: ${(props) => props.theme.colors.white};
    text-align: center;
    margin: 0 auto;
    display: block;
    cursor: pointer;
    margin-top: 4rem;
    transition: all 0.2s;

    &:hover {
        transform: scale(1.05);
    }
`
